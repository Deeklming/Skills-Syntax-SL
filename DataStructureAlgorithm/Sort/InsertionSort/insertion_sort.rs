fn main() {
    let mut a = [9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,5,6];
    println!("before sort: {:?}", a);
    insertion_sort(&mut a);
    println!("after sort:  {:?}", a);
}

fn insertion_sort(ar: &mut [i32]){//오름차순
    let arlen = ar.len();
    for i in 1..arlen{
        let tmp = ar[i];
        let mut k = i;
        while k>0 && ar[k-1]>tmp{
            ar[k] = ar[k-1];
            k-=1;
        }
        ar[k] = tmp;
    }
}
