function solution(t, p) {
  // 크기가 작은 부분 문자열
  let answer = 0;

  for (let i = 0; i < t.length; i++) {}
  
  return answer;
}






function solution(t, p) {
  let numt = Number(t)
  let nump = Number(p)
  var answer = 0;
  for(let i = 0; i < t.length; i++){
      if(t[i] <= nump){
          answer++
      }
  }
  return answer;
}// 실패