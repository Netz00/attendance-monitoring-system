package com.netz00.attendancemonitoringsystem.web.rest;


import com.netz00.attendancemonitoringsystem.domain.Record;
import com.netz00.attendancemonitoringsystem.dto.PostLendingDTO;
import com.netz00.attendancemonitoringsystem.service.RecordService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping(path = "api/v1/records")
public class RecordController {
    RecordService recordService;

    @Autowired
    public RecordController(RecordService recordService) {
        this.recordService = recordService;
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Record registerNewAuthor(@Valid @RequestBody PostLendingDTO postLendingDTO) {
        return recordService.addRecord(postLendingDTO);
    }


}