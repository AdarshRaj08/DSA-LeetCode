class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr1[26] = {0};
        int n1 = ransomNote.length();
        int n2 = magazine.length();

        if(n1 > n2)
            return false;
        

        for(int i=0; i<n2; i++)
        {
            arr1[magazine[i] - 'a']++;
        }
        for(int i=0; i<n1; i++)
        {
            arr1[ransomNote[i] - 'a']--;
            if((arr1[ransomNote[i] - 'a']) < 0)
                return false;
        }
        return true;
    }
};