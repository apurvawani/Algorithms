/*
Alice wrote a sequence of words in CamelCase as a string of letters, s , having the following properties:

1. It is a concatenation of one or more words consisting of English letters.
2. All letters in the first word are lowercase.
3. For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.

Given s , print the number of words in s on a new line.
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class CamelCase {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String testStr = in.next();
        String regEx = "([A-Z])";
        Pattern pattern = Pattern.compile(regEx);
        Matcher matcher = pattern.matcher(testStr);
        int count = 0;
        while (matcher.find())
            count = count + matcher.groupCount();
        System.out.println(count+1);
        
	/*
	char[] arr = testStr.toCharArray();
        int count = 0;
        for(int i = 0 ; i < arr.length ; i++){
            for(char c = 'A' ; c <= 'Z' ; c++){
                if(arr[i]==c){
                    count++;
                }
            }
        }
        System.out.println(count + 1);
	*/
    }
}
