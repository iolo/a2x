# dgrx

Apple II Double Lo-Res Graphics Extension Library

## apis

- init()
- exit()
- cls(color)
- plot(x1, y1, color)
- hline(x1, x2, y1)
- vline(y1, y2, x2, color)
- rect(x1, y1, x2, y2, color)
- fillrect(x1, y1, x2, y2, color)
- pixmap(x1, y1, x2, y2, src, maskColor)
- pixmap(x1, y1, x2, y2, src, color)
- putc(x1, y1, x2, y2, color, ch)
- puts(x1, y1, color, src)
- TODO: read(x1, y1)
- TODO: save(x1, y1, x2, y2, dst)
- TODO: load(x1, y1, x2, y2, src)

## fonts

- 4x6(3x5 bounding box) fonts
