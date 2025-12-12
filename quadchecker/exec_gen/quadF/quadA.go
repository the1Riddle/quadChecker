package quadF

import (
	"fmt"
)

func QuadA(x, y int) {
	if x <= 0 || y <= 0 {
		return
	}

	for row := 1; row <= y; row++ {
		for col := 1; col <= x; col++ {
			switch {
			case row == 1:
				if col == 1 {
					fmt.Print("o")
				} else if col == x {
					fmt.Print("o")
				} else {
					fmt.Print("-")
				}

			case row == y:
				if col == 1 {
					fmt.Print("o")
				} else if col == x {
					fmt.Print("o")
				} else {
					fmt.Print("-")
				}

			default:
				if col == 1 || col == x {
					fmt.Print("|")
				} else {
					fmt.Print(" ")
				}
			}
		}
		fmt.Print("\n")
	}
}
