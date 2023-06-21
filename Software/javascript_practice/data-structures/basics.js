/* Fibonacci */


// Fibonacci loop
function fibonacci_loop(n){
    fibo = [0,1];
    for (let i=2;i<n;i++){
      fibo[i] = fibo[i-2] + fibo[i-1];
    }
    return fibo;
  }
  
  console.log(fibonacci_loop(5));

// recursively
function fibonacci_recur(n){
    return n;
}



/* Factorial */




/* Pr */