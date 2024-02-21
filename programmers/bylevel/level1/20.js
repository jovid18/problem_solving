function solution(s) {
  // 가운데 글자 가져오기
  //s의 길이가 짝수일 때와 홀수 일 때
  //짝수면  n/2-1,n/2 번째 인덱스
  //홀수면 (n-1)/2 번째 인덱스
  //string의 n번째 글자 => string[n]

  if (s.length % 2 === 0) {
    return s[s.length / 2 - 1] + s[s.length / 2];
  } else if (!s.length % 2 === 0) {
    return s[(s.length - 1) / 2];
  }
}
//substring을 하는 방식도 고려

// 4자리 문자열 0123 => 12
// 6자리 문자열 012345 => 23
// n자리 문자열 01...n-1 => (n/2-1)(n/2)

// 3자리 문자열 012 => 1
// 5자리 문자열 01234 => 2
// n자리 문자열 01...n-1 => (n-1)/2
