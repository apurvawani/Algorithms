/*Given Maria's array of scores for a season of n games, find and print the number of times she breaks her record 
for most and least points scored during the season.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BreakingTheRecords {

    static int[] getRecord(int[] s){
        int highestScore = s[0] , lowestScore = s[0];
        int best = 0 , worst = 0;
        for(int s_i = 0 ; s_i < s.length ; s_i++){
            if(s[s_i] > highestScore){
                highestScore = s[s_i];
                best++;
            }
            if(s[s_i] < lowestScore){
                lowestScore = s[s_i];
                worst++;
            }
        }
        int[] result = new int[2];
        result[0] = best;
        result[1] = worst;
        return result;
        // Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] s = new int[n];
        for(int s_i=0; s_i < n; s_i++){
            s[s_i] = in.nextInt();
        }
        int[] result = getRecord(s);
        String separator = "", delimiter = " ";
        for (Integer val : result) {
            System.out.print(separator + val);
            separator = delimiter;
        }
        System.out.println("");
    }
}
