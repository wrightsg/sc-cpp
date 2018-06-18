E.3 – Expressing Business Rules

Objective
- Clearly express business rules and domain.
- It’s OK to write a passing test if it express a valid business rule.

Problem description: Leap Year

Here are the rules for identifying a Leap Year:
- Is leap year if divisible by 400
- Is NOT leap year if divisible by 100 but not by 400
- Is leap year if divisible by 4


package com.codurance.craftingcode.exercise_03_leap_year;

import org.junit.Test;

import static org.hamcrest.Matchers.is;
import static org.junit.Assert.assertThat;

public class YearShould {

    @Test public void
        be_leap_year_when_divisible_by_4() {
	        assertThat(leapYear(1996), is(true));
		        assertThat(leapYear(1997), is(false));
			    }

    @Test public void
        be_a_leap_year_when_divisible_by_400() {
	        assertThat(leapYear(2000), is(true));
		    }

    @Test public void
        not_be_leap_year_when_divisible_by_100_but_not_by_400() {
	        assertThat(leapYear(1700), is(false));
		    }

    private boolean leapYear(int year) {
            return new Year(year).isLeap();
	        }

}


package com.codurance.craftingcode.exercise_03_leap_year;

public class Year {

    private int year;

    public Year(int year) {
            this.year = year;
	        }

    public boolean isLeap() {
            return divisibleBy(100)
	                        ? divisibleBy(400)
				                    : divisibleBy(4);
						        }

    private boolean divisibleBy(int divisor) {
            return year % divisor == 0;
	        }
		}