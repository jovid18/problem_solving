function solution(arr) {
    
  var answer = [];
  if (arr.length === 0 || arr.length === 1) {
    answer.push(-1);
  } else {
    arr.sort((a, b) => b - a);
    for (let i = 0; i < arr.length - 1; i++) {
      answer.push(arr[i]);
    }
  }

  return answer;
}
let arr = [3, 1, 2, 4]; //answer[3,2,4];
