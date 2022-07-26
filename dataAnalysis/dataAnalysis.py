# generate sorted sequences and directionality indexes data by voltage traces heights
# plot voltage traces of 5 individual single synapses and their arithmetic sum
# plot voltage traces of 120 random-sequence multiple synapses of DI(directionality index) = 0~10 compared with arithmetic sum of single synapses
# plot voltage traces of average of random-sequence multiple synapses of different DI compared with arithmetic sum of single synapses

import matplotlib.pyplot as plt
import matplotlib.colors as colors
import matplotlib.cm as cm

f1 = open('dataSingleSyn.csv', mode='r')
linesf1 = f1.readlines()
f1.close()

f2 = open('dataRandomSyn.csv', mode='r')
linesf2 = f2.readlines()
f2.close()

f3 = open('sequences_directionalityIndex.csv', mode='r')
linesf3 = f3.readlines()
f3.close()

time = []
for i in range(12001):
    time.append(float(linesf1[i].strip('\n').split(',')[1]))

voltSingle = []
arithSum = []
base = []
baseAve = 0
for i in range(5):
    base.append(float(linesf1[12003+12006*i].strip('\n').split(',')[151]))
    baseAve += base[i]
baseAve /= 5
for i in range(12001):
    arithSum.append(baseAve)
for i in range(5):
    run = []
    for j in range(12001):
        run.append(float(linesf1[j+12003+12006*i].strip('\n').split(',')[151]))
        arithSum[j] += (run[j]-base[i])
    voltSingle.append(run)

voltRandom = []
sequences = []
directionalityIndex = []
directionality = []
directionalityAve = []
randomPeak = []
randomBase = []
randomHeight = []
directionalityBaseAve = []
for i in range(11):
    directionality.append([])
    directionalityAve.append([])
    directionalityBaseAve.append(0)
    for j in range(12001):
        directionalityAve[i].append(0)
for i in range(120):
    tmp = linesf3[i+1].strip('\n').split(',')
    directionality[int(tmp[6])].append(i)
    seq = []
    for j in range(5):
        seq.append(int(tmp[j+1]))    
    sequences.append(seq)
    directionalityIndex.append(int(tmp[6]))
    randomPeak.append(float(linesf2[24004+12006*i].strip('\n').split(',')[151]))
    randomBase.append(float(linesf2[12003+12006*i].strip('\n').split(',')[151]))
    heightIndex = []
    heightIndex.append(i)
    heightIndex.append(randomPeak[i]-randomBase[i])
    randomHeight.append(heightIndex)
    directionalityBaseAve[int(tmp[6])] += randomBase[i]
    run = []
    for j in range(12001):
        run.append(float(linesf2[j+12003+12006*i].strip('\n').split(',')[151]))
        directionalityAve[int(tmp[6])][j] += run[j]
    voltRandom.append(run)
for i in range(11):
    directionalityBaseAve[i] /= len(directionality[i])
    for j in range(12001):
        directionalityAve[i][j] /= len(directionality[i])

def takeSecond(elem):
    return elem[1]
sortedHeight = sorted(randomHeight, key=takeSecond, reverse=True)

f4 = open('sortedHeightData.csv', mode='w')
print("Run,Height,Sequence,DI,SEQ1,SEQ2,SEQ3,SEQ4,SEQ5", file=f4)
for i in range(120):
    print("{},{},{}-{}-{}-{}-{},{},{},{},{},{},{}".format(sortedHeight[i][0], sortedHeight[i][1], sequences[sortedHeight[i][0]][0], sequences[sortedHeight[i][0]][1], sequences[sortedHeight[i][0]][2], sequences[sortedHeight[i][0]][3], sequences[sortedHeight[i][0]][4], directionalityIndex[sortedHeight[i][0]], sequences[sortedHeight[i][0]][0], sequences[sortedHeight[i][0]][1], sequences[sortedHeight[i][0]][2], sequences[sortedHeight[i][0]][3], sequences[sortedHeight[i][0]][4]), file=f4)
f4.close()

palettenum = 3
palette = ['tab20', 'Set3', 'tab20b']
colornum = [20, 12, 20]
totalcolornum = 0
colormap = []
colorcode = []
for i in range(palettenum):
    totalcolornum += colornum[i]
    colormap.append(cm.get_cmap(palette[i]))
    for j in range(colornum[i]):
        colorcode.append(colors.to_hex(colormap[i](j), keep_alpha=False))

fig = plt.figure(figsize=(16,12))
colorct = 0
for i in range(5):
    if i == 0:
        labelText = "{} ({})".format(i+1, "distal")
    elif i == 4:
        labelText = "{} ({})".format(i+1, "proximal")
    else:
        labelText = i+1
    plt.plot(time, voltSingle[i], label=labelText, color=colorcode[colorct])
    colorct += 1
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Single Synapse", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("SingleSynapse.png")
plt.close()

fig = plt.figure(figsize=(16,12))
colorct = 0
for i in range(5):
    if i == 0:
        labelText = "{} ({})".format(i+1, "distal")
    elif i == 4:
        labelText = "{} ({})".format(i+1, "proximal")
    else:
        labelText = i+1
    plt.plot(time, voltSingle[i], label=labelText, color=colorcode[colorct])
    colorct += 1
plt.plot(time, arithSum, label='arithmetic sum', color=colorcode[colorct])
colorct += 1
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Single Synapse with Arithmetic Sum", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("SingleSynapseWithArithmeticSum.png")
plt.close()

for j in range(11):
    fig = plt.figure(figsize=(16,12))
    colorct = 0
    for i in range(len(directionality[j])):
        labelText = "{}-{}-{}-{}-{}".format(sequences[directionality[j][i]][0],sequences[directionality[j][i]][1],sequences[directionality[j][i]][2],sequences[directionality[j][i]][3],sequences[directionality[j][i]][4])
        plt.plot(time, voltRandom[directionality[j][i]], label=labelText, color=colorcode[colorct])
        colorct += 1    
    if j != 0 and j != 10:
        plt.plot(time, directionalityAve[j], label='average', color=colorcode[colorct])
        colorct += 1
    plt.plot(time, arithSum, label='arithmetic sum', color=colorcode[colorct])
    colorct += 1
    plt.xlabel('Time(ms)', fontsize=20)
    plt.ylabel('Volt(mV)', fontsize=20)
    plt.tick_params(labelsize=16)
    plt.title("Random Multiple Synapses\ndirectionality index = {}".format(j), fontsize=32, loc='center', pad=15.0)
    plt.legend(fontsize=20)
    plt.savefig("RandomMultipleSynapses_DI{}.png".format(j))
    plt.close()
    fig = plt.figure(figsize=(16,12))
    colorct = 0
    for i in range(len(directionality[j])):
        labelText = "{}-{}-{}-{}-{}".format(sequences[directionality[j][i]][0],sequences[directionality[j][i]][1],sequences[directionality[j][i]][2],sequences[directionality[j][i]][3],sequences[directionality[j][i]][4])
        plt.plot(time, voltRandom[directionality[j][i]], label=labelText, color=colorcode[colorct])
        colorct += 1
    if j != 0 and j != 10:
        plt.plot(time, directionalityAve[j], label='average', color=colorcode[colorct])
        colorct += 1
    plt.plot(time, arithSum, label='arithmetic sum', color=colorcode[colorct])
    colorct += 1
    plt.xlim(20, 80)
    plt.ylim(-70.78, -70.757)
    plt.xlabel('Time(ms)', fontsize=20)
    plt.ylabel('Volt(mV)', fontsize=20)
    plt.tick_params(labelsize=16)
    plt.title("Random Multiple Synapses\ndirectionality index = {} zoom in".format(j), fontsize=32, loc='center', pad=15.0)
    plt.legend(fontsize=20)
    plt.savefig("RandomMultipleSynapses_DI{}ZoomIN.png".format(j))
    plt.close()

fig = plt.figure(figsize=(16,12))
colorct = 0
for i in range(11):
    labelText = "DI = {}".format(i)
    plt.plot(time, directionalityAve[i], label=labelText, color=colorcode[colorct])
    colorct += 1
plt.plot(time, arithSum, label='arithmetic sum', color=colorcode[colorct])
colorct += 1
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Random Multiple Synapses\ndirectionality index average", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("RandomMultipleSynapses_DIAve.png")
plt.close()

fig = plt.figure(figsize=(16,12))
colorct = 0
for i in range(11):
    labelText = "DI = {}".format(i)
    plt.plot(time, directionalityAve[i], label=labelText, color=colorcode[colorct])
    colorct += 1
plt.plot(time, arithSum, label='arithmetic sum', color=colorcode[colorct])
colorct += 1
plt.xlim(20, 80)
plt.ylim(-70.78, -70.757)
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Random Multiple Synapses\ndirectionality index average zoom in", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("RandomMultipleSynapses_DIAveZoomIN.png")
plt.close()