package main

import "fmt"

func main() {
	a := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for i := 1; i <= 9; i++ {
		v, err := BinarySearch(a, i)
		if err < 0 {
			break
		} else {
			fmt.Printf("value index: %d\n", v)
		}
	}
}

func BinarySearch(arr []int, value int) (int, int) {
	var left, mid, right, count = 0, 0, len(arr) - 1, 1
	fmt.Printf("value(%d)=> ", value)
	for ; left <= right; count++ {
		mid = left + (right-left)/2
		if arr[mid] == value {
			fmt.Printf("ok, count: %d, ", count)
			return mid, 1
		} else if arr[mid] > value {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	fmt.Printf("fail, count: %d, ", count)
	return mid, -1
}
