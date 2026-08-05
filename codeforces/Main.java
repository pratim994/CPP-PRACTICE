import java.util.*;

// To implement run lenght encoding in java 
// input will be of string hall 
// and output will be of h1a1l2

class Main {
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        String s = sc.nextLine();
        int cnt =1;
        StringBuilder ans = new StringBuilder();
        
        for(int i = 1; i < s.length(); i++){
            
            if(s.charAt(i) == s.charAt(i-1)){
                cnt++;
            }
            else{
                ans.append(cnt).append(s.charAt(i-1));
                cnt = 1;
            }
        }
        
        ans.append(cnt).append(s.charAt(s.length()-1));
        
        
        System.out.println(ans.toString());
        
    }
}
