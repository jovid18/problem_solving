function solution(s) {
  if (s.length === 4 || s.length === 6) {
    let ss = s.split('');
    for (let i = 0; i < ss.length; i++) {
      if (isNaN(ss[i])) {
        return false;
      }
    }
    // 모든 검사를 통과했을 때만 true 반환
    return true;
  }
  // 길이 조건을 만족하지 않으면 false 반환
  return false;
}