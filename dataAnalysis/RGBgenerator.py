# generate a color palette for colors used for plotted labels

import matplotlib.pyplot as plt
import matplotlib.colors as colors
import matplotlib.cm as cm
import matplotlib.patches as patch
from PIL import ImageColor

palettenum = 3
palette = ['tab20', 'Set3', 'tab20b']
palettename = 'ColorPalette({}-{}-{})'.format(palette[0], palette[1], palette[2])
colornum = [20, 12, 20]
totalcolornum = 0
colormap = []
colorcode = []

for i in range(palettenum):
    totalcolornum += colornum[i]
    colormap.append(cm.get_cmap(palette[i]))
    for j in range(colornum[i]):
        code = []
        code.append(colors.to_hex(colormap[i](j), keep_alpha=False))
        code.append(ImageColor.getcolor(code[0], "RGB"))
        colorcode.append(code)

fig, ax = plt.subplots(figsize=(16,12))
ax.invert_yaxis()
for i in range(totalcolornum):
    rec = patch.Rectangle((0, (1/totalcolornum)*i), 0.5, (1/totalcolornum), facecolor=colorcode[i][0], fill=True)
    ax.add_patch(rec)
    ax.text(0, (1/totalcolornum)*(i+1), " ".join((str(colorcode[i][0]), str(colorcode[i][1]))), fontsize=12)
plt.axis('off')
plt.title(palettename, fontsize=14, loc='left')
plt.savefig(palettename+'.png')