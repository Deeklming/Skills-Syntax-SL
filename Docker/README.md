# Docker {: .text-center}

## 목차

---

## network
```bash
docker network create --driver=bridge \
--subnet=172.72.0.0/16 \
--ip-range=172.72.0.0/24 \
--gateway=172.72.0.1 \
custom_network_name
```
--subnet과 --ip-range는 같은 대역

## linux
### snap install
```bash
sudo snap install docker
sudo groupadd -f docker
sudo usermod -aG docker $USER
sudo chown root:docker /var/run/docker.sock
ls -al /var/run/docker.sock
newgrp docker
```

### exec
```bash
docker exec -it {container_id or name} /bin/bash

# alpine
docker exec -it {container_id or name} /bin/sh
```

### network
```bash
docker network create --driver=bridge --subnet=172.22.0.0/16 --ip-range=172.22.1.0/24 --gateway=172.22.1.254 {network_name}
```

## nginx
### container
```bash
docker run --network mynet -p 8001:80 -p 4001:443 -p 2001:22 -v ~/sharedata:/sharedata --name nginx1 -dit nginx:stable-alpine3.17
```

## alpine
### apk
```
apk update
apk search {package}
apk add {package}
apk del {package}
apk stats
```

## debian
```bash
docker run --cpus 1 --memory 1024m --privileged -v F:\\vshare:/vshare --net mynet -p 10023:22 -p 10081:80 -p 10444:443 --name debian1 -dit debian:bookworm-slim
docker run --cpus 1 --memory 1024m --privileged -v F:\\vshare:/vshare --net mynet -p 10024:22 -p 10082:80 -p 10445:443 --name debian2 -dit debian:bookworm-slim

docker exec -it debian1 /bin/bash
docker exec -it debian2 /bin/bash
```
`--privileged` : 관리자 권한 가능

