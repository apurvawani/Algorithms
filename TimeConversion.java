/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.*;

public class TimeConversion {

    static String timeConversion(String s) {
        String[] array = s.split(":");
        String part1 = array[0];
        String part2 = array[1];
        String part3 = array[2];
        char[] arr = part3.toCharArray();
        if(!part1.equals("12") && arr[2]=='P'){
            char[] a = part1.toCharArray();
            a[0] += 1;
            a[1] += 2;
            part1 = String.valueOf(a);
        }
        if(part1.equals("12") && arr[2]=='A'){
            part1 ="00";
        }
        char[] a_rr = new char[2];
        a_rr[0] = arr[0];
        a_rr[1] = arr[1];
        part3 = String.valueOf(a_rr);
        String result = part1 + ":" + part2 + ":" + part3;
        return result;
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String result = timeConversion(s);
        System.out.println(result);
    }
}
