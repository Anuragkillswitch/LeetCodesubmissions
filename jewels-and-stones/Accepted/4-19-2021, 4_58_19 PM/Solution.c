// https://leetcode.com/problems/jewels-and-stones

int numJewelsInStones(char * J, char * S) {
    int num_stonejewels = 0;
    int hashmap[150] = {0}; //covers ASCII values for a-z & A-Z.
   
   while(*S) {
        hashmap[*S++]++;
    }

    while(*J) {
        num_stonejewels+=hashmap[*J++];
    }
    return num_stonejewels;
}