import fs from 'node:fs';

console.log('uint8_t asc[][12] = {');
// convert unihex to binary
// ex. 0020:00000000000000000000000000000000
const LINE_PATTERN = /[\dA-F]+:([\dA-F]+)/g;
for (const line of fs.readFileSync('7x12.hex', 'utf8').split(/\r\n/)) {
  const [code, bitmap] = line.split(':');
  if (!bitmap) {
    continue;
  }
  if (code === 'E010') {
    console.log('};');
    console.log('uint8_t han[][24] = {');
  }
  console.log('//', code, ':');//, bitmap);
  if (bitmap.length == 32) {
    //console.log('eng');
    const buf = [];
    for (let i = 8; i < bitmap.length; i += 2) {
      const hex = bitmap.substring(i, i + 2);
      const bin = parseInt(hex, 16).toString(2).padStart(8, '0');
      //console.log(bin.replaceAll('0', '-').replaceAll('1', '#'));
      const hgrbin = '0b' + '0' + bin[6] + bin[5] + bin[4] + bin[3] + bin[2] + bin[1] + bin[0];
      buf.push(hgrbin);
      //const hgrhex = '0x' + parseInt(hgrbin, 2).toString(16).padStart(2, '0');
      //buf.push(hgrhex);
    }
    console.log('{', buf.join(','), '},');
  } else if (bitmap.length == 64) {
    //console.log('kor');
    const buf = [];
    for (let i = 16; i < bitmap.length; i += 4) {
      const hex = bitmap.substring(i, i + 4);
      const bin = parseInt(hex, 16).toString(2).padStart(16, '0');
      //console.log(bin.replaceAll('0', '-').replaceAll('1', '#'));
      const hgrbin0 = '0b' + '0' + bin[6] + bin[5] + bin[4] + bin[3] + bin[2] + bin[1] + bin[0];
      const hgrbin1 = '0b' + '0' + bin[13] + bin[12] + bin[11] + bin[10] + bin[9] + bin[8] + bin[7];
      buf.push(hgrbin0);
      buf.push(hgrbin1);
      //const hgrhex0 = '0x' + parseInt(hgrbin0, 2).toString(8).padStart(2, '0');
      //const hgrhex1 = '0x' + parseInt(hgrbin1, 2).toString(8).padStart(2, '0');
      //buf.push(hgrhex0);
      //buf.push(hgrhex1);
    }
    console.log('{', buf.join(','), '},');
  } else {
    console.error('unknown');
    process.exit(1);
  }
}
console.log('};');
