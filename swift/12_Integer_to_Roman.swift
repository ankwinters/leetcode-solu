//
//  main.swift
//
//  Copyright © 2018 ckp. All rights reserved.

import Foundation

class Solution {
    func intToRoman(_ num: Int) -> String {
        var roman_str:String = ""
        var tmp_num = num
        // check if > 1000
        var val = 1000
        if tmp_num >= val {
            let m = tmp_num / val
            for _ in 1...m {
                roman_str += "M"
            }
            tmp_num = tmp_num - m * val
        }
        // 100-900
        val = 100
        if tmp_num >= val {
            let cdm = tmp_num / val
            if cdm < 4 {
                for _ in 1...cdm {
                    roman_str += "C"
                }
            } else if cdm == 4 {
                roman_str += "CD"
            } else if cdm >= 5 && cdm < 9 {
                
                roman_str += "D"
                for _ in 5..<cdm {
                    roman_str += "C"
                }
            } else if cdm == 9 {
                roman_str += "CM"
            }
            tmp_num = tmp_num - cdm * val
        }
        // 10-90
        val = 10
        if tmp_num >= val {
            let xlc = tmp_num / val
            if xlc < 4 {
                for _ in 1...xlc {
                    roman_str += "X"
                }
            } else if xlc == 4 {
                roman_str += "XL"
            } else if xlc >= 5 && xlc < 9 {
                roman_str += "L"
                for _ in 5..<xlc {
                    roman_str += "X"
                }
            } else if xlc == 9 {
                roman_str += "XC"
            }
            tmp_num = tmp_num - xlc * val
        }
        
        // 1-9
        val = 1
        if tmp_num >= val {
            let ivx = tmp_num
            if ivx < 4 {
                for _ in 1...ivx {
                    roman_str += "I"
                }
            } else if ivx == 4 {
                roman_str += "IV"
            } else if ivx >= 5 && ivx < 9 {
                roman_str += "V"
                for _ in 5..<ivx {
                    roman_str += "I"
                }
            } else if ivx == 9 {
                roman_str += "IX"
            }
        }
        
        return roman_str
    }
}

var s = Solution()

print(s.intToRoman(58))

