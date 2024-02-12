# Linux {: .text-center}

## 목차
### [common index](#common)
[cpuinfo](#cpuinfo)

### [tools index](#tools)
[scp](#scp)
[curl](#curl)

### [packages index](#packages)
[docker snap install](#docker-snap-install)
[tree install (ubuntu)](#tree-install-ubuntu)
[python 3.11 install (ubuntu20)](#python-311-install-ubuntu20)

### [tips index](#tips)
[swap](#swap)
[inode noatime ext4](#inode-noatime-ext4)

---

# common
## cpuinfo
```bash
dmidecode #package
lscpu | less
cat /proc/cpuinfo
uname -a
```
Architecture, Byte Order, CPU count, Model name 등 cpu 정보 출력

---

# tools
## scp
scp [옵션] [파일명] [원격지_id]@[원격지_ip]:[받는 위치]
```bash
scp testfile1 root@127.0.0.1:/pos
```
목적지로 파일 전송

## curl
### get
```bash
curl http://127.0.0.1/?key1=value1&key2=value2
curl -G http://127.0.0.1:80/ -d key1=value1 -d key2=value2
```

### post
```bash
curl http://127.0.0.1:80/ -d key1=value1 -d key2=value2
curl http://127.0.0.1/ -d "key1=value1&key2=value2"
curl -X POST -d "key=value" -G http://127.0.0.1/
```

### json
```bash
curl -X POST -H "Content-Type: application/json" -d '{"key1": number, "key2": "string"}' http://127.0.0.1/
curl -X POST -H "Content-Type: application/json" -d "{\"key1\": number, \"key2\": \"string\"}" http://127.0.0.1/
curl -X POST -H "Content-Type: application/json" -d '{"key1": number, "key2": "string"}' -G http://127.0.0.1:5000/user/login/
```

### cookie
```bash
curl http://127.0.0.1/ -b "session=dumdum1"
```

### file upload
```bash
curl http://127.0.0.1/ -d "@/bin/bash"
curl http://127.0.0.1/ -F pwdfile=@/bin/bash -F hello=aaa
```

---

# packages
## docker snap install
```bash
sudo snap install docker
sudo groupadd -f docker
sudo usermod -aG docker $USER
sudo chown root:docker /var/run/docker.sock
ls -al /var/run/docker.sock
newgrp docker
```

## tree install (ubuntu)
```bash
sudo apt install tree
tree -I "__pycache__|venv|ask.sh" -a > tree.txt
```
`-I` : 제외 파일 및 디렉터리

## python 3.11 install (ubuntu20)
```bash
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt update
sudo apt install python3.11 python3.11-venv
(옵션) $ sudo apt install python3.11-dev python3.11-gdbm python3.11-tk

vim .bashrc
	(추가) alias python='python3.11'
	(추가) alias pip='python3.11 -m pip'

# python3.11 pip upgrade error시
curl -sS https://bootstrap.pypa.io/get-pip.py | python3.11
```

---

# tips
## swap
특별한 경우 없으면 스왑기능을 끄면 시스템 성능상 좋음, SSD 수명연장에도 도움

### swap remove
1. `sudo swapoff -v /swapfile` : 페이징 및 스왑핑을 비활성화
2. `sudo cp /etc/fstab /etc/fstab.bak` : 다음 명령을 통해 파일을 백업
3. `sudo sed -i '/swapfile/d' /etc/fstab` : 'swapfile'이 포함된 줄 삭제 (가능한 편집기를 열어서 주석 처리하는게 좋음)
4. `sudo rm /swapfile` : /swapfile 파일 제거

### swap create
1. `sudo dd if=/dev/zero of=/swapfile count=4096 bs=1MiB` : Linux 파티션의 디스크 공간을 사전 할당 (count로 4GB 할당, RAM size에 따라 다르게 필요)
2. `sudo chmod 600 /swapfile` : 파일 권한을 변경
3. `sudo mkswap /swapfile` : 파일을 Linux 스왑 영역으로 설정
4. `sudo swapon /swapfile` : 작동
5. `echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab` : 영구적으로 만들려면 /etc/fstab 파일에 '/swapfile none swap sw 0 0' 이라는 새 줄을 작성
6. `sudo swapon --show` : 스왑 공간의 상태 확인

## inode noatime ext4
리눅스는 파일을 읽을 때마다 inode에 마지막 읽은 시간(access time)을 기록하는 기능이 활성화되어 있는데, noatime(no access time)을 비활성화 하는 것이 좋음
- 이유
    1. 시스템 성능에 유리
    2. SSD 수명 연장
1. `sudo vim /etc/fstab` : 편집기로 열기
2. 모든 파티션의 noatime을 0으로 만듬
```
# 예시
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
   /                             ext4     noatime         0        0
```

---
