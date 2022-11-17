package main

import ( 
	"fmt"
	"time"
)
func is_prime(n int){
	for i:=2;i<n/i;i++ {
		if n%i == 0{
			fmt.Println(n, ": false")
			return
		}
	}
	fmt.Println(n, ": true")
}
func main(){
	fmt.Println("hello world")
	for i:=0;i<50;i++ {
		go is_prime(i)
	}
	time.Sleep(10000)
}