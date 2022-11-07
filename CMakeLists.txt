cmake_minimum_required(VERSION 3.23)
project(cpp_workspace)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_workspace
        AStar_PracticeExams/exam1/distribution/distribution.cpp
        AStar_PracticeExams/exam1/haybalestacking/haybalestacking.cpp
        AStar_PracticeExams/exam1/milkingcows/milkingcows.cpp
        AStar_PracticeExams/exam2/initials/intials.cpp
        AStar_PracticeExams/exam2/matchsticks/matchsticks.cpp
        AStar_PracticeExams/exam2/plantremoval/plantremoval.cpp
        AStar_PracticeExams/exam3/lasersandmirrors/lasers.cpp
        AStar_PracticeExams/exam3/squarepastures/square.cpp
        AStar_PracticeExams/exam3/visitingcows/visitingcows.cpp
        AStar_PracticeExams/exam4/lotus/lotus.cpp
        AStar_PracticeExams/exam4/network/network.cpp
        AStar_PracticeExams/exam4/traffic/traffic.cpp
        cf/804/a/a.cpp
        cf/804/b/b.cpp
        cf/804/c/c.cpp
        cf/804/d/d.cpp
        GoogleKickStart_2022/Practice_1/centauri/centauri.cpp
        GoogleKickStart_2022/Practice_1/h_index/h_index.cpp
        GoogleKickStart_2022/Practice_1/hex/hex.cpp
        GoogleKickStart_2022/Practice_1/sample/sample.cpp
        GoogleKickStart_2022/Practice_2/building/building.cpp
        GoogleKickStart_2022/Practice_2/expressions/expressions.cpp
        GoogleKickStart_2022/Practice_2/parcel/parcel.cpp
        GoogleKickStart_2022/Practice_2/sample/sample.cpp
        GoogleKickStart_2022/Practice_2/sherlock/sherlock.cpp
        HHSProgramming/PR2/binarynumbers/binarynumber.cpp
        HHSProgramming/PR3/disturbedpeople/disturbedpeople.cpp
        HHSProgramming/PR3/playlist/playlist.cpp
        HHSProgramming/PR3/rumor/rumor.cpp
        HHSProgramming/PR4/disturbingwords/disturbingwords.cpp
        HHSProgramming/PR4/shootingpractice/shootingpractice.cpp
        HHSProgramming/PR4/spitting/spitting.cpp
        HHSProgramming/PR5/amateurchemist/chemist.cpp
        HHSProgramming/PR5/coins/coins.cpp
        HHSProgramming/PR5/fishfordinner/fishfordinner.cpp
        HHSProgramming/PR6/kevin/kevin.cpp
        HPI_2022/p1/p1.cpp
        HPI_2022/p10/p10.cpp
        HPI_2022/p2/p2.cpp
        HPI_2022/p4/p4.cpp
        HPI_2022/tiebreaker/tie.cpp
        othercode/template/template.cpp
        othercode/test/test.cpp
        "USACO_21-22/Contest 1/closestcowwins/closest.cpp"
        "USACO_21-22/Contest 1/connectingbarns/connectingbarns.cpp"
        "USACO_21-22/Contest 1/convolutedintervals/intervals.cpp"
        "USACO_21-22/Contest 2/cereal2/cereal.cpp"
        "USACO_21-22/Contest 2/frisbee/frisbee.cpp"
        "USACO_21-22/Contest 2/soulmates/soulmates.cpp"
        "USACO_21-22/Contest 3/email/email.cpp"
        "USACO_21-22/Contest 3/email/email2.cpp"
        "USACO_21-22/Contest 3/gift/gift.cpp"
        "USACO_21-22/Contest 3/robot/robot.cpp"
        "USACO_21-22/Contest 3/robot/robot1.cpp"
        "USACO_21-22/Contest 4/operation/operation.cpp"
        "USACO_21-22/Contest 4/subset/setset.cpp"
        "USACO_21-22/Contest 4/visits/visits.cpp"
        "USACO_21-22/Contest 4/visits/visits2.cpp"
        USACO_Practice/ABCs/ABCs.cpp
        USACO_Practice/Acowdemia/acowdemia.cpp
        USACO_Practice/adjdifferences/adj.cpp
        USACO_Practice/boxers/boxers.cpp
        USACO_Practice/capital/capital.cpp
        USACO_Practice/comfortable/comfortable.cpp
        USACO_Practice/convention2/convention2.cpp
        USACO_Practice/cowntagion/cowntagion.cpp
        USACO_Practice/diamondcollector/diamond.cpp
        USACO_Practice/fenceplanning/fenceplan.cpp
        USACO_Practice/fencesplit/split.cpp
        USACO_Practice/fieldreduction/reduce.cpp
        USACO_Practice/flightcheck/flightcheck.cpp
        USACO_Practice/gcdblackboard/gcd.cpp
        USACO_Practice/haybalestacking/haybalestacking.cpp
        USACO_Practice/knapsack/knapsack.cpp
        USACO_Practice/knapsack/knapsack2.cpp
        USACO_Practice/lemonadeline/lemonade.cpp
        USACO_Practice/magicship/magicship.cpp
        USACO_Practice/moobuzz/moobuzz.cpp
        USACO_Practice/moocast/moocast.cpp
        USACO_Practice/moocast2/moocast.cpp
        USACO_Practice/mooney/time.cpp
        USACO_Practice/mooparticle/mooparticle.cpp
        USACO_Practice/moutains/mountains.cpp
        USACO_Practice/notescaping/escaping.cpp
        USACO_Practice/notescaping/escaping2.cpp
        USACO_Practice/notimetopaint/paint.cpp
        USACO_Practice/pairedup/pairup.cpp
        USACO_Practice/pasture/pasture.cpp
        USACO_Practice/rangeupdates/rangeupdates.cpp
        USACO_Practice/reststops/reststops.cpp
        USACO_Practice/ski_course/ski_level.cpp
        USACO_Practice/socdist/socdist.cpp
        USACO_Practice/spacedout/spacedout.cpp
        USACO_Practice/stuckinrut/rut.cpp
        USACO_Practice/talent/talent.cpp
        USACO_Practice/tasksanddeadline/tasks.cpp
        USACO_Practice/towers/towers.cpp
        USACO_Practice/treediameter/diamter.cpp
        USACO_Practice/whycross/whycross.cpp
        USACO_Practice/wormsort/wormsort.cpp
        USACO_Practice/yearofthecow/cowyear.cpp
        xcamp/01.09.22/candy/candy.cpp
        xcamp/01.09.22/justgreen/green.cpp
        xcamp/01.09.22/meetingplace/meeting.cpp
        xcamp/01.09.22/wherebessie/bessie.cpp
        xcamp/01.16.22/cross/cross.cpp
        xcamp/01.16.22/painting/painting.cpp
        xcamp/01.16.22/painting/painting1.cpp
        xcamp/01.16.22/USB/usb.cpp
        xcamp/01.23.22/dancemooves/dance.cpp
        xcamp/01.23.22/MazeTacToe/mazetactoe.cpp
        xcamp/01.23.22/solvemaze/solve.cpp
        xcamp/01.30.22/goodsubarrays/goodsub.cpp
        xcamp/01.30.22/milkvisits/milkvisits.cpp
        xcamp/01.30.22/rental/rental.cpp
        xcamp/02.06.22/berrypicking/berry.cpp
        xcamp/02.06.22/network/network.cpp
        xcamp/02.06.22/socialdistancing/distancing.cpp
        xcamp/02.13.22/cereal/cereal.cpp
        xcamp/02.13.22/highcard/highcard.cpp
        xcamp/03.05.22/anonymity/anon.cpp
        xcamp/03.05.22/gamemaster/game.cpp
        xcamp/03.05.22/greatsequence/sequence.cpp
        xcamp/03.05.22/inversiongraph/inversion.cpp
        xcamp/03.12.22/monsters/monsters.cpp
        xcamp/03.12.22/palindromes/palindromes.cpp
        xcamp/03.12.22/particles/particles.cpp
        xcamp/03.12.22/system/system.cpp
        xcamp/03.19.22/book/book.cpp
        xcamp/03.19.22/decrease/decrease.cpp
        xcamp/03.19.22/decrease/decreaserev2.cpp
        xcamp/03.19.22/dragon/dragon.cpp
        xcamp/03.19.22/rumor/rumor.cpp
        xcamp/04.10.22/message/message.cpp
        xcamp/04.10.22/shortest/shortest.cpp
        xcamp/04.10.22/visitfj/visitfj.cpp
        xcamp/04.16.22/dining/dining.cpp
        xcamp/04.16.22/discount/discount.cpp
        xcamp/04.16.22/lasers/lasers.cpp
        xcamp/04.16.22/lasers/lasers2.cpp
        xcamp/04.16.22/pumping/pumping.cpp
        "xcamp/04.16.22/shortestroutes II/shortest.cpp"
        xcamp/04.23.22/construction/construction.cpp
        xcamp/04.23.22/moocast/moocast.cpp
        xcamp/04.23.22/superbull/superbull.cpp
        xcamp/04.30.22/closing/closing.cpp
        xcamp/04.30.22/mootube/mootube.cpp
        xcamp/04.30.22/planetsqueries_II/planets.cpp
        xcamp/05.07.22/book/book.cpp
        xcamp/05.07.22/edit/edit.cpp
        xcamp/05.07.22/fruit/feast.cpp
        xcamp/05.07.22/hps/hps.cpp
        xcamp/05.14.22/barnpainting/barnpainting.cpp
        xcamp/05.14.22/checklist/checklist.cpp
        xcamp/05.14.22/convention/convention.cpp
        xcamp/05.14.22/desc/desc.cpp
        xcamp/05.14.22/shortcut/shortcut.cpp
        xcamp/05.14.22/teamwork/teamwork.cpp
        xcamp/05.21.22/snakes/snakes.cpp
        xcamp/06.11.22/increasing/increasing.cpp
        xcamp/06.11.22/increasing/increasing2.cpp
        xcamp/06.11.22/pizzeria/pizzeria.cpp
        xcamp/06.18.22/DRQ/drsq.cpp
        xcamp/06.18.22/DRQ/drsq2.cpp
        xcamp/06.18.22/photo/photo.cpp
        xcamp/06.18.22/salary/salary.cpp
        xcamp/06.25.22/haircut/haircut.cpp
        xcamp/06.25.22/matching/copy.cpp
        xcamp/06.25.22/matching/matching.cpp
        xcamp/06.25.22/whycross/whycross.cpp
        xcamp/07.02.22/matching/matching.cpp
        xcamp/07.02.22/palindrome/palindrome.cpp
        xcamp/07.02.22/patterns/patterns.cpp
        xcamp/07.16.22/censoring/censor.cpp
        xcamp/07.16.22/circlecross/circlecross.cpp
        xcamp/07.16.22/DRSQ/drsq.cpp
        xcamp/07.23.22/portals/portals.cpp
        xcamp/07.23.22/replication/replication.cpp
        xcamp/07.23.22/telephone/telephone.cpp
        xcamp/07.30.22/maxflow/maxflow.cpp
        xcamp/07.30.22/milkingorder/milkorder.cpp
        xcamp/07.30.22/milkvisits/milkvisits.cpp
        xcamp/entrance_test/AxB/AxB.cpp
        xcamp/entrance_test/reversepair/reversepair.cpp
        xcamp/entrance_test/serpentinematrix/serpentine.cpp)
