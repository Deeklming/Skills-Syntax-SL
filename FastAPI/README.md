# FastAPI
Python Open Source Web Framework

## Links
[FastAPI Homepage](https://fastapi.tiangolo.com/)
[FastAPI Documentation ko](https://fastapi.tiangolo.com/ko/)
[Django gitignore](https://github.com/tiangolo/fastapi/blob/master/.gitignore)

## FastAPI Feature

## FastAPI Preparation

## FastAPI sample
```py
from typing import Optional
from fastapi import FastAPI
from pydantic import BaseModel
from enum import Enum

class ModelName(str, Enum):
    alexnet="alexnet"
    resnet="resnet"
    lenet="lenet"

class Item(BaseModel):
    name: str
    description: Optional[str]=None
    price: float
    tax: Optional[float]=None

app=FastAPI()

@app.get("/")
async def root():
    return {"Message": "Hello World"}

@app.post("/items/")
async def create_item(item: Item):
    item_dict=item.dict()
    if item.tax:
        price_with_tax=item.price+item.tax
        item_dict.update({"price_with_tax": price_with_tax})
    return item_dict
```

## FastAPI Commands
### sharing the environment
```
pip freeze > requirements.txt  // requirements.txt 생성 명령어
pip install -r requirements.txt // install 명령어
```
현재 pip에 설치된 환경 공유
