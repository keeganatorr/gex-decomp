typedef struct Node Node;
struct Node {
  Node *nd_next;
  Node *nd_prev;
};

typedef struct Mid {
  int field_0;
  Node *field_4;
} Mid;

typedef struct Event {
  int eventNumber;
  void *eventToCall;
} Event;

typedef struct GXObject {
  char pad0[0xc];
  Mid *mid;
  void *field_10;
  char pad14[0x1c];
  void *field_30;
  char pad34[0xa8];
  int field_dc;
  char pad_e0[0xb4];
  Event events[12];
} GXObject;

extern "C" void SCRIPT_DoEvent_00433590(GXObject *obj, void *script, void *eventToCall, int eventNumber);
extern "C" int GXAniScript_004641f0;

extern "C" void GEX_Target(GXObject *param_1, int param_2)
{
  if (param_2 != 0) {
    int i;
    Event *event;
    event = &param_1->events[0];
    i = 12;
    do {
      if (event->eventNumber == 0x1a) {
        SCRIPT_DoEvent_00433590(param_1, &GXAniScript_004641f0, event->eventToCall, event->eventNumber);
      }
      event++;
      i--;
    } while (i != 0);
    return;
  }

  {
    Mid *mid = param_1->mid;
    Node *node = mid->field_4;
    if (node != 0 && (node = node->nd_next) != 0 && (node = node->nd_next) != 0) {
      param_1->field_10 = node;
      node = mid->field_4->nd_next->nd_prev;
      if (node != 0) {
        param_1->field_30 = node;
      }
    }
  }
  param_1->field_dc = 0x100;
}
