class Solution {
    List<String> res = new ArrayList<String>();

    public List<String> generateParenthesis(int n) {
        recuse(0,0,"",n);
        return res;
    }
    public void recuse(int l,int r,String s, int n){
        if(s.length()==n*2){
            res.add(s);
            return;
        }
        if(l<n){
            recuse(l+1,r,s+"(",n);
        }
        if(r<l){
            recuse(l,r+1,s+")",n);
        }
    }
}