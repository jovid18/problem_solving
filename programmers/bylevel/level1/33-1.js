function solution(t, p) {
  var answer = 0;
  // t :"012345" =>길이 6
  // p :"0123" => 길이 4
  // 여기서 p의 길이만큼 봐야하는데
  // 0123, 1234,2345 => 3개 (6-4+1)
  for (let i = 0; i < t.length - p.length + 1; ++i) {
    //지금 보고 있는 부분을 substring으로 뺌 (i부터 i+p.length 까지)
    let str = +t.substring(i, i + p.length);
    //그렇게 뽑은 문자열을 숫자로 바꾸고 문자열을 숫자 p로 바꾼것과 비교해서 작거나 같으면 answer++;
    if (+str <= +p) answer++;
  }
  return answer;
}
let t = '3141592';
let p = '271';

solution(t, p);
