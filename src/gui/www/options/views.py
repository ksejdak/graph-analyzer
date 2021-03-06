from django.shortcuts import render_to_response
from django.template import RequestContext
from django.core.context_processors import csrf

from tools.CoreOptions import CoreOptions
from tools.SystemStatus import SystemStatus
from tools.LoggingOptions import LoggingOptions
from tools.DatabaseOptions import DatabaseOptions

def render_options(request):
    # get system status
    systemStatus = SystemStatus()
    systemStatus.get()
    
    c = RequestContext(request, {"version": systemStatus.version, "options": True})
    c.update(csrf(request))
    
    coreOptions = CoreOptions()
    loggingOptions = LoggingOptions()
    databaseOptions = DatabaseOptions()
    
    # ===================================== GET =====================================

    if(request.method == "GET"):
        # get core options
        coreOptions.get()
    
        # get logging options
        loggingOptions.get()
        
        # get database options
        databaseOptions.get()
        
    # ===================================== POST =====================================
    
    # save options if "Save" clicked
    if(request.method == "POST"):
        # core options
        coreOptions.graphs_dir = request.POST["graphsDirectory"]
        coreOptions.tmp_pcap_dir = request.POST["tmpPcapDirectory"]
        coreOptions.tcpflow_params = request.POST["tcpflowParams"]
        coreOptions.emulation_steps = request.POST["emulationSteps"]
        if("skipBigFiles" in request.POST):
            coreOptions.skip_big_files = True
        else:
            coreOptions.skip_big_files = False
        coreOptions.skip_big_files_size = request.POST["skipBigFilesSize"]
        if("skipBrokenSamples" in request.POST):
            coreOptions.skip_broken_samples = True
        else:
            coreOptions.skip_broken_samples = False
        coreOptions.skip_broken_samples_size = request.POST["skipBrokenSamplesSize"]
        if("skipEmptySamples" in request.POST):
            coreOptions.skip_empty_samples = True
        else:
            coreOptions.skip_empty_samples = False
        if("skipNoSyscallAndLoopSamples" in request.POST):
            coreOptions.skip_nosyscall_noloop_samples = True
        else:
            coreOptions.skip_nosyscall_noloop_samples = False
        
        # logging level
        levelDictStr = {"OFF": 0, "Low": 1, "Normal": 2, "High": 3}
        levelStr = request.POST["logLevel"]
        loggingOptions.level = levelDictStr[levelStr]
        
        # status options
        if("exportStatusDB" in request.POST):
            loggingOptions.exportStatusDB = True
        else:
            loggingOptions.exportStatusDB = False
        
        # description options
        if("exportDescriptionXML" in request.POST):
            loggingOptions.exportDescriptionXML = True
        else:
            loggingOptions.exportDescriptionXML = False
        
        # database options
        databaseOptions.driver = request.POST["dbDriver"]
        databaseOptions.host = request.POST["dbHost"]
        databaseOptions.name = request.POST["dbName"]
        databaseOptions.user = request.POST["dbUser"]
        databaseOptions.password = request.POST["dbPassword"]
        
        coreOptions.save()
        loggingOptions.save()
        databaseOptions.save()
        c.update({"dataSaved": True})
    
    # update core options
    c.update({"graphsDirectory": coreOptions.graphs_dir,
			  "tmpPcapDirectory": coreOptions.tmp_pcap_dir,
			  "tcpflowParams": coreOptions.tcpflow_params,
			  "emulationSteps": coreOptions.emulation_steps,
              "skipBigFiles": coreOptions.skip_big_files,
              "skipBigFilesSize": coreOptions.skip_big_files_size,
              "skipBrokenSamples": coreOptions.skip_broken_samples,
              "skipBrokenSamplesSize": coreOptions.skip_broken_samples_size,
              "skipEmptySamples": coreOptions.skip_empty_samples,
              "skipNoSyscallAndLoopSamples": coreOptions.skip_nosyscall_noloop_samples})

    # update logging options
    c.update({"logLevel": int(loggingOptions.level),
              "exportDescriptionXML": loggingOptions.exportDescriptionXML,
			  "exportStatusDB": loggingOptions.exportStatusDB})
    
    # update database options
    c.update({"dbDriver": databaseOptions.driver,
			  "dbHost": databaseOptions.host,
              "dbName": databaseOptions.name,
              "dbUser": databaseOptions.user,
              "dbPassword": databaseOptions.password})
    
    return render_to_response("options.html", c)