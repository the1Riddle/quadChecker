package quadF

import (
	"fmt"
)

func QuadC(x, y int) {
	if x <= 0 || y <= 0 {
		return
	}

	for row := 1; row <= y; row++ {
		for col := 1; col <= x; col++ {
			switch {
			case row == 1:
				if col == 1 {
					fmt.Print("A")
				} else if col == x {
					fmt.Print("A")
				} else {
					fmt.Print("B")
				}

			case row == y:
				if col == 1 {
					fmt.Print("C")
				} else if col == x {
					fmt.Print("C")
				} else {
					fmt.Print("B")
				}

			default:
				if col == 1 || col == x {
					fmt.Print("B")
				} else {
					fmt.Print(" ")
				}
			}
		}
		fmt.Print("\n")
	}
}
