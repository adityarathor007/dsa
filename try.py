import os
import time

def disk_seek_time(filename):
    start = time.time()
    with open(filename, 'r') as f:
        f.read(1024)
    end = time.time()
    disk_seek_time = end - start
    return disk_seek_time*(1e9)
filename = "cpp.json"
print("Disk Seek Time:", disk_seek_time(filename), "ns")
