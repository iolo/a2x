apple2-expedition
=================

## VIDEOROM.BAS

애플//x의 비디오 롬에 들어있는 모든 폰트를 화면에 출력.

1. 빈 작업용 디스켓 이미지 만들기
```console
$ java -jar ac.jar -dos140 disk2.dsk
```

2. 작업용 디스켓의 파일 목록 보기
```console
$ java -jar ac.jar -l disk2.dsk
```
3. 작업용 디스켓 이미지에서 파일 삭제
```console
$ java -jar ac.jar -d disk2.dsk videorom.bas
```

4. 작업용 디스켓 이미지에 파일 추가
```console
$ java -jar ac.jar -bas disk2.dsk videorom.bas < videorom.bas
```

5. 주어진 디스켓 이미지를 드라이브2에 꽂고 부팅(드라이브1에는 도스 마스터 디스켓이 기본으로 꽂혀있음)
```console
$ linapple -b --d2 disk2.dsk
```

6. 드라이브2의 파일 목록 보기
```console
] CATALOG,D2
```

7. 드라이브2의 베이직 파일 로드
```console
] LOAD VIDEOROM.BAS,D2
```

8. 40x24 텍스트모드에서 실행
```console
] RUN
```

9. 80x24 텍스트모드에서 실행
```console
] PR#3
] RUN
```

9. 80x24 모드 활성화 이후에 40x24 모드로 전환
```console
] <ESC>4
```

