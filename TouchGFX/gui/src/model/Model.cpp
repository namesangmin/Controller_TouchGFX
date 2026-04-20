#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

// 모델에 직접 값을 넣어.
// 외부에서 들어온 데이터를 model에 넣어
// 데이터는 외부에서 들어온 메세지 큐에 있는 데이터임.
// UI에 나타낼 정보를 담고 있음
// presenter로부터 데이터와 이벤트를 전달받아 변경된다.

void Model::tick()
{
	messageBuffer msg;
	if(xQueueReceive( qid, &msg, 0 ) == pdPASS){
		modelListener->notifyOutputData(msg);
	}
}

