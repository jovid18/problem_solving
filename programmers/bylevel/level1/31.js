function solution(s) {
  // 이상한 문자 만들기
  // 각 단어는 하나 이상의 공백문자
  // 각 단어의 짝수번째 알파벳은 대문자로,
  // 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴
  // 전에 이중 배열 했듯이 풀어보는 걸로.
  // ex) s = "try hello world"
  let answer = '';
  let arr = s.split(' '); // try, hello, word
  for (let i = 0; i < arr.length; i++) {
    // "try"
    let arrString = arr[i];
    for (let j = 0; j < arrString.length; j++) {
      // t, r, y
      if (j % 2 === 0) {
        answer += arrString[j].toUpperCase();
      } else {
        answer += arrString[j].toLowerCase();
      }
    }
    if (i !== arr.length - 1) answer += ' ';
  }
  return answer;
}
