#!/bin/bash
ac.sh -d disk2.dsk $1
ac.sh -l disk2.dsk
ac.sh -bas disk2.dsk $1 < $1
ac.sh -l disk2.dsk
linapple -b --d2 disk2.dsk
