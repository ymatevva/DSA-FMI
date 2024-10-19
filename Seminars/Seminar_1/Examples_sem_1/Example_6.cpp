
//Example 5:

int smth(int *arr, size_t sizeArr){
    unsigned res = 0;
    for (int i = 1; i <= sizeArr; i++) {
        for (int j = 1; j <= sizeArr; j+=i) {
            res++;
        }
    }
    return res;
}

//So the outer loop makes sizeArr steps.
//The inner loop makes n/i steps, so its complexity is O(n/i) => this is the complexity of the harmonious order so => log(n)
// => n*O(log(n)) => O(n*log(n))