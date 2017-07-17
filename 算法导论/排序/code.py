import time
import numpy

# 排序算法
def insert_sort(x):
    b = [x[0]] * len(x)
    for i in range(1, len(x)):
        j = i - 1
        while j >= 0 and b[j] > x[i]:
            b[j + 1] = b[j]
            j = j - 1
        b[j + 1] = x[i]
    return(b)
insert_sort_time = 0
sort_time = 0
for i in range(1000):
    a = numpy.random.uniform(size = 100)
    time1 = time.time()
    insert_sort(a)
    insert_sort_time += (time.time() - time1)
    time2 = time.time()
    a.sort()
    sort_time += (time.time() - time2)

print("insert_sort time is %s, origin sort time is %s" %
      (insert_sort_time, sort_time))
