E.2 – Test-Driving Algorithms

Objective
- Grow an algorithm bit by bit
- Delay treating exceptions (in this case, because they are more complex)
- Intentionally cause duplication
- Focus on simple structures first


Problem description: Roman Numerals Converter

Implement a Roman numeral converter. The code must be able to take decimals
up to 3999 and convert to their roman equivalent.

Examples
1    - I
5    - V
10   - X
50   - L
100  - C
500  - D
1000 - M
2499 - MMCDXCIX
3949 - MMMCMXLIX

Transformation Priority Premise - TPP
({}–>nil) no code at all->code that employs nil
(nil->constant)
(constant->constant+) a simple constant to a more complex constant
(constant->scalar) replacing a constant with a variable or an argument
(statement->statements) adding more unconditional statements.
(unconditional->if) splitting the execution path
(scalar->array)
(array->container)
(statement->recursion)
(if->while)
(expression->function) replacing an expression with a function or algorithm
(variable->assignment) replacing the value of a variable.

package com.codurance;

import junitparams.JUnitParamsRunner;
import junitparams.Parameters;
import org.junit.Test;
import org.junit.runner.RunWith;

import static com.codurance.RomanNumeralConverter.romanFor;
import static org.assertj.core.api.Assertions.assertThat;

@RunWith(JUnitParamsRunner.class)
public class RomanNumeralConverterShould {

    @Test
        @Parameters({
	            "1, I",
		                "2, II",
				            "3, III",
					                "4, IV",
							            "5, V",
								                "7, VII",
										            "9, IX",
											                "10, X",
													            "18, XVIII",
														                "30, XXX",
																            "38, XXXVIII",
																	                "40, XL",
																			            "50, L",
																				                "90, XC",
																						            "100, C",
																							                "400, CD",
																									            "500, D",
																										                "900, CM",
																												            "1000, M",
																													                "999, CMXCIX",
																															            "3423, MMMCDXXIII",
																																        })
																																	    public void
																																	        convert_arabic_numbers_into_roman_numerals(int arabic, String roman) {
																																		        assertThat(romanFor(arabic)).isEqualTo(roman);
																																			    }


}




package com.codurance;

class RomanNumeralConverter {

    static String romanFor(int arabic) {
            String roman = "";

        for (ArabicToRoman arabicToRoman : ArabicToRoman.values()) {
	            while (arabic >= arabicToRoman.arabic) {
		                    roman += arabicToRoman.roman;
				                    arabic -= arabicToRoman.arabic;
						                }
								        }

        return roman;
	    }

    enum ArabicToRoman {
            THOUSAND(1000, "M"),
	            NINE_HUNDRED(900, "CM"),
		            FIVE_HUNDRED(500, "D"),
			            FOUR_HUNDRED(400, "CD"),
				            HUNDRED(100, "C"),
					            NINETY(90, "XC"),
						            FIFTY(50, "L"),
							            FORTY(40, "XL"),
								            TEN(10, "X"),
									            NINE(9, "IX"),
										            FIVE(5, "V"),
											            FOUR(4, "IV"),
												            ONE(1, "I");

        private final int arabic;
	        private final String roman;

        ArabicToRoman(int arabic, String roman) {
	            this.arabic = arabic;
		                this.roman = roman;
				        }
					    }

}