# a simple tool for a quick check for data correctness and similarity
# output difference between group [ref] and all groups in [data]

fread = open('dataRandomSyn.csv', mode='r')
lines = fread.readlines()
fread.close()

data = []
ref = []
for i in range(1, 120):
    group = []
    for j in range(12001):
        if i == 1:
            ref.append(float(lines[j+12003+12006*i].strip('\n').split(',')[151]))
        group.append(float(lines[j+12003+12006*i].strip('\n').split(',')[151])-ref[j])
    data.append(group)

fwrite = open('check.txt', mode='w')
for i in range(119):
    print(data[i], file=fwrite)
fwrite.close()