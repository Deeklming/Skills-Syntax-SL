package main

import (
	"fmt"
)

func main() {
	sn := "aigowabcdkfjwoiabaebabc"
	p := bruteForceMethod(sn, "abc")
	if p != -1 {
		fmt.Printf("%d에 위치함\n", p)
	} else {
		println("찾는 문자열이 없음")
	}
}

func bruteForceMethod(s string, m string) int {
	mlen := len(m)
	checklen := len(s) - mlen
	for i := 0; i <= checklen; i++ {
		alltrue := 0
		for j := 0; j < mlen; j++ {
			fmt.Printf("%c", s[i+j])
			if s[i+j] != m[j] {
				break
			} else {
				alltrue++
			}
		}
		println()
		if alltrue == mlen {
			return i
		}
	}
	return -1
}
