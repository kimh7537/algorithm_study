import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {
        int n, k, temp;
        int res = 0, start = 0;
        List<Integer> v = new ArrayList<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0 ; i < n ; i++){
            temp = Integer.parseInt(br.readLine());
            v.add(temp);
            if(temp <= k){
                start++;
            }
        }

        start--;
        while(k > 0){
            if(k - v.get(start) >= 0){
                res++;
                k -= v.get(start);
            }
            else{
                start--;
            }
        }

        System.out.println(res);
    }
}