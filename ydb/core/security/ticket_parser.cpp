#include "ticket_parser_impl.h"
#include "ticket_parser.h"

namespace NKikimr {

class TTicketParser : public TTicketParserImpl<TTicketParser> {
    using TThis = TTicketParser;
    using TBase = TTicketParserImpl<TTicketParser>;
    using TBase::TBase;
    using TTokenRecord = TBase::TTokenRecordBase;

    friend TBase;

    enum class ETokenType {
        Unknown,
        Unsupported,
        AccessService,
        Builtin,
        Login,
    };

    THashMap<TString, TTokenRecord> UserTokens;

    THashMap<TString, TTokenRecord>& GetUserTokens() {
        return UserTokens;
    }
};

IActor* CreateTicketParser(const NKikimrProto::TAuthConfig& authConfig) {
    return new TTicketParser(authConfig);
}

}
