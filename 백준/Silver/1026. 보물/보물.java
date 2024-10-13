
import java.util.*;
import java.io.*;

public class Main{

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();

        int num = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            num = Integer.parseInt(st.nextToken());
            a.add(num);
        }

        StringTokenizer st1 = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            num = Integer.parseInt(st1.nextToken());
            b.add(num);
        }

        Collections.sort(a);
        Collections.sort(b, Collections.reverseOrder());

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (a.get(i) * b.get(i));
        }
        System.out.println(res);
    }
}