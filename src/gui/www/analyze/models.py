from django.db import models
from tasks.models import Task

# ShellcodeSample table
class Sample(models.Model):
	name = models.CharField(max_length = 200)
	extracted_from = models.CharField(max_length = 200)
	graph_name = models.CharField(max_length = 200)
	capture_date = models.CharField(max_length = 10)
	size = models.CharField(max_length = 10)
	file_type = models.CharField(max_length = 50)
	file_size = models.CharField(max_length = 10)
	shellcode_offset = models.CharField(max_length = 10)
	comment = models.CharField(max_length = 3000)
	task = models.ForeignKey(Task)
	
	def __unicode__(self):
		return self.name

# SyscallAnalyzer table
class API(models.Model):
	dll = models.CharField(max_length = 20)
	syscall = models.CharField(max_length = 20)

	def __unicode__(self):
		return self.syscall

# APIAssignment table
class APIAssignment(models.Model):
	api = models.ForeignKey(API)
	sample = models.ForeignKey(Sample)
	
	def __unicode__(self):
		return self.api.syscall

# GraphHash table
class Hash(models.Model):
	hash = models.CharField(max_length = 10)

	def __unicode__(self):
		return self.hash

# HashAssignment table
class HashAssignment(models.Model):
	hash = models.ForeignKey(Hash)
	sample = models.ForeignKey(Sample)
	
	def __unicode__(self):
		return self.hash.hash

# LoopDetector table
class Loop(models.Model):
	hash = models.CharField(max_length = 10)
	iterations = models.CharField(max_length = 10)
	size = models.CharField(max_length = 10)
	start = models.CharField(max_length = 10)
	vertexes = models.CharField(max_length = 2000)
	comment = models.CharField(max_length = 3000)
	
	def __unicode__(self):
		return self.hash

# LoopAssignment table
class LoopAssignment(models.Model):
	loop = models.ForeignKey(Loop)
	sample = models.ForeignKey(Sample)
	
	def __unicode__(self):
		return self.loop.hash