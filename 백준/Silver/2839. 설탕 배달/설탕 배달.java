import java.io.*;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n  = Integer.parseInt(br.readLine());
        br.close();
        
        int ans = 0;
        
        while(n >= 0){
            if(n % 5 == 0){
                ans += n / 5;
                System.out.println(ans);
                return;
            }
            n -= 3;
            ans++;
        }
        System.out.println(-1);
    }
}