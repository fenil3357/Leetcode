bool cmp(vector<int> &v1, vector<int> &v2) {
    return (v1[0] < v2[0]);
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
        sort(meets.begin(), meets.end(), cmp);

        // Priority queue for engaged rooms
        // {current_meet_end_time, room_number}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > engaged;

        // Priotiy queue for non-engaged rooms
        // {room_number} 
        priority_queue<int, vector<int>, greater<int>> unused;


        // Freq of meets in each room
        unordered_map<int, int> freq;

        // At start all rooms are empty
        for(int i=0; i<n; i++) 
            unused.push(i);

        for(auto &it : meets) {
            int start_time = it[0], end_time = it[1];

            // Move the meeting rooms in engaged, with end_time <= s, to unused
            while(!engaged.empty() && engaged.top().first <= start_time) {
                int room = engaged.top().second;
                engaged.pop();

                unused.push(room);
            }

            // Choosing the room with lower room_number
            if(!unused.empty()) {
                int room = unused.top();
                unused.pop();

                freq[abs(room)]++;

                // Mark the room as engaged
                engaged.push({end_time, room});
            }

            // All rooms are full then wait for the room with nearest ending time to empty
            else {
                pair<long long, int> topMost = engaged.top();
                engaged.pop();

                freq[abs(topMost.second)]++;

                // New end_time of meet will be sum(end_time_of_prev_meet, duration)
                long long newEnd = topMost.first;
                newEnd += (end_time - start_time);

                // Mark the room as engaged
                engaged.push({newEnd, topMost.second});
            }
        }

        // Find the lowest room_number with maximum frequency
        int mx = 0;

        for(int i=0; i<n; i++) 
            if(freq[i] > freq[mx]) 
                mx = i;

        return mx;
    }
};