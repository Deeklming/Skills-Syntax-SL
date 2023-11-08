fn main(){
    let r = [1,2,3,4,5,6,7,8];
    for i in 1..=8{
        let vi = binary_search(&r, i);
        if let None = vi{
            break;
        }else{
            println!("value index: {}", vi.unwrap());
        }
    }
}

fn binary_search(arr: &[i32], value: i32)->Option<usize>{
    let size = arr.len();
    let mut count = 0;
    let mut lmr:(usize, usize, usize) = (0,0,size-1);//left, middle, right
    print!("value({})=> ", value);
    while lmr.0<=lmr.2{
        count+=1;
        lmr.1 = lmr.0+(lmr.2-lmr.0)/2;
        if arr[lmr.1]==value{
            print!("ok, count: {}, ", count);
            return Some(lmr.1);
        }else if arr[lmr.1]<value{
            lmr.0 = lmr.1+1;
        }else{
            lmr.2 = lmr.1-1;
        }
    }
    print!("fail, count: {}, ", count);
    None
}