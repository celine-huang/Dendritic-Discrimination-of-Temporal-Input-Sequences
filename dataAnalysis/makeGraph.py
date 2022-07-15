# plot voltage traces of 5 individual single synapses and their arithmetic sum
# plot voltage traces of 120 random-sequence multiple synapses of DI(directionality index) = 0~10 compared with arithmetic sum of single synapses
# plot voltage traces of average of random-sequence multiple synapses of different DI compared with arithmetic sum of single synapses

import matplotlib.pyplot as plt

f1 = open('dataSingleSyn.csv', mode='r')
f2 = open('dataRandomSyn.csv', mode='r')
f3 = open('sequences_directionalityIndex.csv', mode='r')

linesf1 = f1.readlines()
linesf2 = f2.readlines()
linesf3 = f3.readlines()

f1.close()
f2.close()
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
directionality = []
directionalityAve = []
randomBase = []
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
    randomBase.append(float(linesf2[12003+12006*i].strip('\n').split(',')[151]))
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

fig1 = plt.figure(1, figsize=(16,12))
for i in range(5):
    if i == 0:
        labelText = "{} ({})".format(i+1, "distal")
    elif i == 4:
        labelText = "{} ({})".format(i+1, "proximal")
    else:
        labelText = i+1
    plt.plot(time, voltSingle[i], label=labelText)
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Single Synapse", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("SingleSynapse.png")

fig2 = plt.figure(2, figsize=(16,12))
for i in range(5):
    if i == 0:
        labelText = "{} ({})".format(i+1, "distal")
    elif i == 4:
        labelText = "{} ({})".format(i+1, "proximal")
    else:
        labelText = i+1
    plt.plot(time, voltSingle[i], label=labelText)
plt.plot(time, arithSum, label='arithmetic sum')
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Single Synapse with Arithmetic Sum", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("SingleSynapseWithArithmeticSum.png")

figDI = []
figDIZoomIN = []
for j in range(11):
    figDI.append([])
    figDI[j] = plt.figure(j+3, figsize=(16,12))
    for i in range(len(directionality[j])):
        labelText = "{}-{}-{}-{}-{}".format(sequences[directionality[j][i]][0],sequences[directionality[j][i]][1],sequences[directionality[j][i]][2],sequences[directionality[j][i]][3],sequences[directionality[j][i]][4])
        plt.plot(time, voltRandom[directionality[j][i]], label=labelText)    
    if j != 0 and j != 10:
        plt.plot(time, directionalityAve[j], label='average')
    plt.plot(time, arithSum, label='arithmetic sum')
    plt.xlabel('Time(ms)', fontsize=20)
    plt.ylabel('Volt(mV)', fontsize=20)
    plt.tick_params(labelsize=16)
    plt.title("Random Multiple Synapses\ndirectionality index = {}".format(j), fontsize=32, loc='center', pad=15.0)
    plt.legend(fontsize=20)
    plt.savefig("RandomMultipleSynapses_DI{}.png".format(j))
    figDIZoomIN.append([])
    figDIZoomIN[j] = plt.figure(j+14, figsize=(16,12))
    for i in range(len(directionality[j])):
        labelText = "{}-{}-{}-{}-{}".format(sequences[directionality[j][i]][0],sequences[directionality[j][i]][1],sequences[directionality[j][i]][2],sequences[directionality[j][i]][3],sequences[directionality[j][i]][4])
        plt.plot(time, voltRandom[directionality[j][i]], label=labelText)
    if j != 0 and j != 10:
        plt.plot(time, directionalityAve[j], label='average')
    plt.plot(time, arithSum, label='arithmetic sum')
    plt.xlim(20, 80)
    plt.ylim(-70.78, -70.757)
    plt.xlabel('Time(ms)', fontsize=20)
    plt.ylabel('Volt(mV)', fontsize=20)
    plt.tick_params(labelsize=16)
    plt.title("Random Multiple Synapses\ndirectionality index = {} zoom in".format(j), fontsize=32, loc='center', pad=15.0)
    plt.legend(fontsize=20)
    plt.savefig("RandomMultipleSynapses_DI{}ZoomIN.png".format(j))

figDIAve = plt.figure(25, figsize=(16,12))
for i in range(11):
    labelText = "DI = {}".format(i)
    plt.plot(time, directionalityAve[i], label=labelText)
plt.plot(time, arithSum, label='arithmetic sum')
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Random Multiple Synapses\ndirectionality index average", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("RandomMultipleSynapses_DIAve.png")

figDIAveZoomIN = plt.figure(26, figsize=(16,12))
for i in range(11):
    labelText = "DI = {}".format(i)
    plt.plot(time, directionalityAve[i], label=labelText)
plt.plot(time, arithSum, label='arithmetic sum')
plt.xlim(20, 80)
plt.ylim(-70.78, -70.757)
plt.xlabel('Time(ms)', fontsize=20)
plt.ylabel('Volt(mV)', fontsize=20)
plt.tick_params(labelsize=16)
plt.title("Random Multiple Synapses\ndirectionality index average zoom in", fontsize=32, loc='center', pad=15.0)
plt.legend(fontsize=20)
plt.savefig("RandomMultipleSynapses_DIAveZoomIN.png")