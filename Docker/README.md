# Docker

## network
```bash
docker network create --driver=bridge \
--subnet=172.72.0.0/16 \
--ip-range=172.72.0.0/24 \
--gateway=172.72.0.1 \
custom_network_name
```
--subnet과 --ip-range는 같은 대역
