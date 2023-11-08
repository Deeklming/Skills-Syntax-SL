fn main() {
    let mut a = [9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,5,6];
    println!("before sort:      {:?}", a);
    shell_sort(&mut a, true);
    println!("ascending  sort:  {:?}", a);
    shell_sort(&mut a, false);
    println!("descending sort:  {:?}", a);
}

fn shell_sort(ar: &mut [i32], opt: bool){//true면 오름차순, false면 내림차순
    let arlen = ar.len() as i32;
    let mut v = 1;
    while v < arlen/9{//초기값 설정, 서로 배수가 되지 않도록 하기 위해 홀짝 반복
        v = v*3+1;
    }
    if opt{
        while v>0{
            for i in v..arlen{
                let tmp = ar[i as usize];
                let mut k = i-v;
                while k>=0 && ar[k as usize]>tmp{
                    ar[(k+v) as usize] = ar[k as usize];
                    k-=v;
                }
                ar[(k+v) as usize] = tmp;
            }
            v/=3;
        }
    }else{
        while v>0{
            for i in v..arlen{
                let tmp = ar[i as usize];
                let mut k = i-v;
                while k>=0 && ar[k as usize]<tmp{
                    ar[(k+v) as usize] = ar[k as usize];
                    k-=v;
                }
                ar[(k+v) as usize] = tmp;
            }
            v/=3;
        }
    }
}
