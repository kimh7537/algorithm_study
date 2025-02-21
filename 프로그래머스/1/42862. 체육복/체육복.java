import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        ArrayList<Integer> v = new ArrayList<>();
        
        // Initialize ArrayList with 1s
        for (int i = 0; i < n + 2; i++) {
            v.add(1);
        }
        
        // Mark lost students
        for (int student : lost) {
            v.set(student, v.get(student) - 1);
        }
        
        // Mark reserve students
        for (int student : reserve) {
            v.set(student, v.get(student) + 1);
        }
        
        // Check for possible lending
        for (int i = 1; i < n + 1; i++) {
            if (v.get(i) == 0 && v.get(i-1) > 1) {
                v.set(i-1, v.get(i-1) - 1);
                v.set(i, v.get(i) + 1);
            } else if (v.get(i) == 0 && v.get(i+1) > 1) {
                v.set(i+1, v.get(i+1) - 1);
                v.set(i, v.get(i) + 1);
            }
        }
        
        // Count students with gym clothes
        for (int i = 1; i < n + 1; i++) {
            if (v.get(i) >= 1) answer++;
        }
        
        // Debug print (commented out)
        /*
        for (Integer num : v) {
            System.out.print(num + " ");
        }
        */
        
        return answer;
    }
}