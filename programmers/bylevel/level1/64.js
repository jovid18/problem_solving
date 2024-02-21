function solution(id_list, report, k) {
  let reportSet = new Set(report); // 중복 제거
  let userReported = {}; // 사용자별 신고당한 횟수
  let userReports = {}; // 사용자별 신고한 대상
  id_list.forEach((id) => {
    userReported[id] = 0;
    userReports[id] = new Set();
  });

  reportSet.forEach((r) => {
    let [reporter, reported] = r.split(" ");
    if (!userReports[reporter].has(reported)) {
      userReports[reporter].add(reported);
      userReported[reported]++;
    }
  });

  let banned = new Set();
  Object.keys(userReported).forEach((user) => {
    if (userReported[user] >= k) {
      banned.add(user);
    }
  });

  let answer = id_list.map((reporter) => {
    return Array.from(userReports[reporter]).filter((reported) => banned.has(reported)).length;
  });

  return answer;
}
