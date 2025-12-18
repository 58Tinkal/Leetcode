var canVisitAllRooms = function(rooms) {
    let vis = new Set();
    let st = [0];
    vis.add(0);

    while (st.length) {
        let room = st.pop();

        for (let key of rooms[room]) {
            if (!vis.has(key)) {
                vis.add(key);
                st.push(key);
            }
        }
    }

    return vis.size === rooms.length;
};
