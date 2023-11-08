## Decription
레이캐스팅 원리를 이용하여 3D 그래픽으로 표현한 1인칭 시점의 미로입니다. 최초의 FPS이자 세계적으로 유명한 [Wolfenstein 3D](http://users.atw.hu/wolf3d/) 게임에서 영감을 받았습니다.

## Features
- 자연스러운 움직임과 벽 충돌 감지
- 동서남북에 다른 벽 텍스쳐를 디스플레이
- description file을 특정 룰에 따라 검사하고 파싱하여 미로 생성

## Preview
![image](https://github.com/nemotheswimmer/cub3D/assets/88709878/c0182362-b0d9-4455-9f96-645295ac42ce)

## Enviroment
(현재 클러스터 아이맥 크기에 맞춰져 있는 한계 있음)

## Usage
`make && ./cub3D descriptionfile/2.cub`
혹은
description file 규칙에 따라 새로운 맵을 직접 생성하여 프로그램 실행 시 첫 번째 인자에 넣어주세요.

## Controls
|키|동작|
|---|---|
|`←`|왼쪽 보기|
|`→`|오른쪽 보기|
|W|앞으로 이동|
|A|왼쪽으로 이동|
|S|뒤로 이동|
|D|오른쪽으로 이동|
|ESC|프로그램 종료|

## Peer Reviews
<img width="530" alt="image" src="https://github.com/nemotheswimmer/cub3D/assets/88709878/1b981e90-8fe3-4dd4-afef-6b0fc54b33f6">
<img width="530" alt="image" src="https://github.com/nemotheswimmer/cub3D/assets/88709878/f2e7dd4e-45d9-4aba-9aa9-a4f0950b8374">
<img width="530" alt="image" src="https://github.com/nemotheswimmer/cub3D/assets/88709878/26e9bd36-0114-4c38-8dc2-88bec16a7ea8">

## Blog Post
코드에 대한 자세한 설명이 [Lode's Computer Graphics Tutorial: Raycasting에 대한 조금 긴 사설](https://velog.io/@letmeshare46/Lodes-Computer-Graphics-Tutorial-Raycasting에-대한-조금-긴-사설-ejnvpz1p)에 있습니다.
