function solution(survey, choices) {
  let MBTI = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };
  for (let i = 0; i < survey.length; ++i) {
    if (choices[i] < 4) {
      MBTI[survey[i][0]] += 4 - choices[i];
    } else if (choices[i] > 4) {
      MBTI[survey[i][1]] += choices[i] - 4;
    }
  }
  var answer = "";
  answer += MBTI["R"] >= MBTI["T"] ? "R" : "T";
  answer += MBTI["C"] >= MBTI["F"] ? "C" : "F";
  answer += MBTI["J"] >= MBTI["M"] ? "J" : "M";
  answer += MBTI["A"] >= MBTI["N"] ? "A" : "N";
  return answer;
}
