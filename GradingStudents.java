import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class GradingStudents {

    static int[] solve(int[] grades){
        int[] multipleOfFive = new int[13];
        int t = 40;
        for(int j = 0 ; j<13 ; j++){
            multipleOfFive[j] = t;
            t = t + 5;
        }
        for(int i = 0 ; i<grades.length ; i++){
            int j = 0;
            while(j<13){
                int r = multipleOfFive[j] - grades[i];
                if(r>0 && r<3){
                    grades[i] = multipleOfFive[j];
                }
                j++;
            }
        }
        return grades;// Complete this function
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] grades = new int[n];
        for(int grades_i=0; grades_i < n; grades_i++){
            grades[grades_i] = in.nextInt();
        }
        int[] result = solve(grades);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? "\n" : ""));
        }
        System.out.println("");
        

    }
}
